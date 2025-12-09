#!/bin/bash
set -e

BIN_DIR="/opt/trinitycore/bin"
ETC_DIR="/opt/trinitycore/etc"
BACKUP_DIR="/opt/trinitycore/etc-backup"
SQL_DIR="/opt/trinitycore/sql"
DATA_DIR="/opt/trinitycore/data"

DB_HOST="db"
DB_USER="root"
DB_PASS="trinity"

echo ">>> TrinityCore MASTER Entrypoint initialised <<<"

# --- 1. CONFIG RESTORATION (Volume Fix) ---
# Check if the backup directory exists (created by Dockerfile)
if [ -d "$BACKUP_DIR" ]; then
    # Check if the mounted directory is empty (missing the .dist file)
    if [ ! -f "$ETC_DIR/authserver.conf.dist" ]; then
        echo "Volume mount detected (etc dir is empty). Restoring config files from backup..."
        cp -r "$BACKUP_DIR/." "$ETC_DIR/"
        echo "Restore complete."
    fi
else
    echo "WARNING: Backup directory not found. Ideally, rebuild the image using --no-cache."
fi

# Config Helper Function
set_config() {
    local file=$1
    local key=$2
    local value=$3
    if [ -f "$file" ]; then
        sed -i "s|^$key\s*=.*|$key = \"$value\"|g" "$file"
    fi
}

# --- 2. CONFIG PREPARATION ---
# Create config files from templates if they do not exist
if [ ! -f "$ETC_DIR/authserver.conf" ]; then
    cp "$ETC_DIR/authserver.conf.dist" "$ETC_DIR/authserver.conf"
fi
if [ ! -f "$ETC_DIR/worldserver.conf" ]; then
    cp "$ETC_DIR/worldserver.conf.dist" "$ETC_DIR/worldserver.conf"
fi

echo "Applying configuration settings..."

# Update Authserver Config
set_config "$ETC_DIR/authserver.conf" "LoginDatabaseInfo" "$DB_HOST;3306;$DB_USER;$DB_PASS;auth"

# Update Worldserver Config
set_config "$ETC_DIR/worldserver.conf" "LoginDatabaseInfo"     "$DB_HOST;3306;$DB_USER;$DB_PASS;auth"
set_config "$ETC_DIR/worldserver.conf" "WorldDatabaseInfo"     "$DB_HOST;3306;$DB_USER;$DB_PASS;world"
set_config "$ETC_DIR/worldserver.conf" "CharacterDatabaseInfo" "$DB_HOST;3306;$DB_USER;$DB_PASS;characters"
set_config "$ETC_DIR/worldserver.conf" "DataDir"               "$DATA_DIR"
# Enable auto-updates for Master branch
set_config "$ETC_DIR/worldserver.conf" "Updates.EnableDatabases" "1"
set_config "$ETC_DIR/worldserver.conf" "Updates.AutoSetup"       "1"

# --- 3. WAIT FOR DATABASE ---
echo "Waiting for database connection..."
# Loop until the database responds
while ! mysqladmin ping -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" --silent; do
    sleep 2
done
echo "Database is ready."

# --- 4. AUTO INSTALLATION (First Run Only) ---
# Check if the database has explicitly been initialised
if ! mysql -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" -e "USE auth; SELECT 1 FROM realmlist LIMIT 1;" 2>/dev/null; then
    echo ">>> Starting initial setup for MASTER branch... <<<"

    if [ -d "$SQL_DIR" ]; then
        # A. Create Structure
        mysql -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" < "$SQL_DIR/create/create_mysql.sql"

        # B. Import Base SQL
        echo "Importing base SQL files..."
        mysql -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" auth < "$(find $SQL_DIR/base -name 'auth_database.sql')"
        mysql -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" characters < "$(find $SQL_DIR/base -name 'characters_database.sql')"
        mysql -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" world < "$(find $SQL_DIR/base -name 'world_database.sql')"

        # C. TDB Download (Master Logic)
        echo "Searching for latest TDB for MASTER..."
        
        # Filter Logic: Select files starting with 'TDB_full_' but EXCLUDE those containing '335'
        LATEST_URL=$(curl -s https://api.github.com/repos/TrinityCore/TrinityCore/releases/latest | \
            jq -r '.assets[] | select(.name | startswith("TDB_full_") and (.name | contains("335") | not)) | .browser_download_url')
        
        if [ -n "$LATEST_URL" ] && [ "$LATEST_URL" != "null" ]; then
            echo "Found TDB: $LATEST_URL"
            echo "Downloading..."
            curl -L -o /tmp/tdb.7z "$LATEST_URL"
            
            echo "Extracting..."
            7z e /tmp/tdb.7z -o/tmp/tdb_extracted -y
            
            echo "Importing TDB World Data..."
            mysql -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" world < "$(find /tmp/tdb_extracted -name '*.sql' | head -n 1)"
            
            # Cleanup
            rm -rf /tmp/tdb.7z /tmp/tdb_extracted
            echo "TDB Import completed."
        else
            echo "WARNING: TDB URL not found. The server will start with an empty world."
        fi
    else
        echo "ERROR: SQL directory not found inside container."
    fi
fi

# --- 5. REALM IP SETUP ---
if [ ! -z "$TRINITY_REALM_IP" ] && [ "$1" = "auth" ]; then
    echo "Setting Realm IP to: $TRINITY_REALM_IP"
    mysql -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" auth -e "UPDATE realmlist SET address = '$TRINITY_REALM_IP' WHERE id = 1;" 2>/dev/null || true
fi

# --- 6. START SERVER ---
if [ "$1" = "auth" ]; then
    echo "Starting Authserver..."
    exec "$BIN_DIR/authserver"
elif [ "$1" = "world" ]; then
    echo "Starting Worldserver..."
    exec "$BIN_DIR/worldserver"
else
    exec "$@"
fi
