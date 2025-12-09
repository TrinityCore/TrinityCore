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

# --- 1. CONFIG RESTORE ---
# Fix for empty volume mount
if [ -d "$BACKUP_DIR" ]; then
    if [ ! -f "$ETC_DIR/authserver.conf.dist" ]; then
        echo "Volume mount detected (etc dir is empty). Restoring config files from backup..."
        cp -r "$BACKUP_DIR/." "$ETC_DIR/"
        echo "Restore complete."
    fi
fi

# Config Helper
set_config() {
    local file=$1
    local key=$2
    local value=$3
    if [ -f "$file" ]; then
        sed -i "s|^$key\s*=.*|$key = \"$value\"|g" "$file"
    fi
}

# --- 2. CONFIG SETUP ---
if [ ! -f "$ETC_DIR/authserver.conf" ]; then
    cp "$ETC_DIR/authserver.conf.dist" "$ETC_DIR/authserver.conf"
fi
if [ ! -f "$ETC_DIR/worldserver.conf" ]; then
    cp "$ETC_DIR/worldserver.conf.dist" "$ETC_DIR/worldserver.conf"
fi

echo "Applying configuration..."
set_config "$ETC_DIR/authserver.conf" "LoginDatabaseInfo" "$DB_HOST;3306;$DB_USER;$DB_PASS;auth"
set_config "$ETC_DIR/worldserver.conf" "LoginDatabaseInfo"     "$DB_HOST;3306;$DB_USER;$DB_PASS;auth"
set_config "$ETC_DIR/worldserver.conf" "WorldDatabaseInfo"     "$DB_HOST;3306;$DB_USER;$DB_PASS;world"
set_config "$ETC_DIR/worldserver.conf" "CharacterDatabaseInfo" "$DB_HOST;3306;$DB_USER;$DB_PASS;characters"
set_config "$ETC_DIR/worldserver.conf" "DataDir"               "$DATA_DIR"
set_config "$ETC_DIR/worldserver.conf" "Updates.EnableDatabases" "1"
set_config "$ETC_DIR/worldserver.conf" "Updates.AutoSetup"       "1"

# --- 3. WAIT FOR DB ---
echo "Waiting for database..."
while ! mysqladmin ping -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" --silent; do
    sleep 2
done
echo "Database ready."

# --- 4. FIRST RUN SETUP ---
if ! mysql -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" -e "USE auth; SELECT 1 FROM realmlist LIMIT 1;" 2>/dev/null; then
    echo ">>> Starting initial setup... <<<"
    
    if [ -d "$SQL_DIR" ]; then
        mysql -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" < "$SQL_DIR/create/create_mysql.sql"
        
        echo "Importing base SQL..."
        mysql -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" auth < "$(find $SQL_DIR/base -name 'auth_database.sql')"
        mysql -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" characters < "$(find $SQL_DIR/base -name 'characters_database.sql')"
        mysql -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" world < "$(find $SQL_DIR/base -name 'world_database.sql')"
        
        echo "Downloading TDB..."
        # Filter logic to exclude 335 files
        LATEST_URL=$(curl -s https://api.github.com/repos/TrinityCore/TrinityCore/releases/latest | \
            jq -r '.assets[] | select(.name | startswith("TDB_full_") and (.name | contains("335") | not)) | .browser_download_url')
        
        if [ -n "$LATEST_URL" ] && [ "$LATEST_URL" != "null" ]; then
            echo "Found TDB: $LATEST_URL"
            curl -L -o /tmp/tdb.7z "$LATEST_URL"
            7z e /tmp/tdb.7z -o/tmp/tdb_extracted -y
            mysql -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" world < "$(find /tmp/tdb_extracted -name '*.sql' | head -n 1)"
            rm -rf /tmp/tdb.7z /tmp/tdb_extracted
        else
            echo "WARNING: TDB URL not found."
        fi
    fi
fi

# --- 5. REALM IP ---
if [ ! -z "$TRINITY_REALM_IP" ] && [ "$1" = "auth" ]; then
    mysql -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" auth -e "UPDATE realmlist SET address = '$TRINITY_REALM_IP' WHERE id = 1;" 2>/dev/null || true
fi

# --- 6. START ---
if [ "$1" = "auth" ]; then
    exec "$BIN_DIR/authserver"
elif [ "$1" = "world" ]; then
    exec "$BIN_DIR/worldserver"
else
    exec "$@"
fi
