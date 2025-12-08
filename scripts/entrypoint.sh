#!/bin/bash
set -e

BIN_DIR="/opt/trinitycore/bin"
ETC_DIR="/opt/trinitycore/etc"
SQL_DIR="/opt/trinitycore/sql"
DATA_DIR="/opt/trinitycore/data"

# DB Zugangsdaten
DB_HOST="db"
DB_USER="root"
DB_PASS="trinity"

echo ">>> TrinityCore MASTER Entrypoint gestartet <<<"

# Funktion zum Setzen von Config-Werten
set_config() {
    local file=$1
    local key=$2
    local value=$3
    sed -i "s|^$key\s*=.*|$key = \"$value\"|g" "$file"
}

# --- 1. CONFIG SETUP ---
if [ ! -f "$ETC_DIR/authserver.conf" ]; then
    cp "$ETC_DIR/authserver.conf.dist" "$ETC_DIR/authserver.conf"
fi
if [ ! -f "$ETC_DIR/worldserver.conf" ]; then
    cp "$ETC_DIR/worldserver.conf.dist" "$ETC_DIR/worldserver.conf"
fi

echo "Konfiguriere Server..."
set_config "$ETC_DIR/authserver.conf" "LoginDatabaseInfo" "$DB_HOST;3306;$DB_USER;$DB_PASS;auth"

set_config "$ETC_DIR/worldserver.conf" "LoginDatabaseInfo"     "$DB_HOST;3306;$DB_USER;$DB_PASS;auth"
set_config "$ETC_DIR/worldserver.conf" "WorldDatabaseInfo"     "$DB_HOST;3306;$DB_USER;$DB_PASS;world"
set_config "$ETC_DIR/worldserver.conf" "CharacterDatabaseInfo" "$DB_HOST;3306;$DB_USER;$DB_PASS;characters"
set_config "$ETC_DIR/worldserver.conf" "DataDir"               "$DATA_DIR"

# Updates aktivieren (Wichtig für Master)
set_config "$ETC_DIR/worldserver.conf" "Updates.EnableDatabases" "1"
set_config "$ETC_DIR/worldserver.conf" "Updates.AutoSetup"       "1"

# --- 2. WARTE AUF DATENBANK ---
echo "Warte auf Datenbank Verbindung..."
while ! mysqladmin ping -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" --silent; do
    sleep 2
done
echo "Datenbank ist erreichbar."

# --- 3. AUTO INSTALLATION (Wenn DB leer) ---
if ! mysql -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" -e "USE auth; SELECT 1 FROM realmlist LIMIT 1;" 2>/dev/null; then
    echo ">>> Datenbank leer. Starte Initial-Setup für MASTER... <<<"

    # A. Struktur erstellen
    mysql -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" < "$SQL_DIR/create/create_mysql.sql"

    # B. Basis SQLs importieren
    echo "Importiere Base SQLs..."
    mysql -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" auth < "$(find $SQL_DIR/base -name 'auth_database.sql')"
    mysql -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" characters < "$(find $SQL_DIR/base -name 'characters_database.sql')"
    mysql -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" world < "$(find $SQL_DIR/base -name 'world_database.sql')"

    # C. TDB Download & Import (MASTER LOGIK UPDATE)
    echo "Suche neueste TDB für MASTER auf GitHub..."
    
    # LOGIK: Nimm Datei, die mit "TDB_full_" beginnt UND NICHT "335" enthält.
    # Das fängt "TDB_full_1125.25101..." ab, ignoriert aber "TDB_full_335..."
    LATEST_URL=$(curl -s https://api.github.com/repos/TrinityCore/TrinityCore/releases/latest | \
        jq -r '.assets[] | select(.name | startswith("TDB_full_") and (.name | contains("335") | not)) | .browser_download_url')
    
    if [ -n "$LATEST_URL" ] && [ "$LATEST_URL" != "null" ]; then
        echo "Gefundene TDB: $LATEST_URL"
        echo "Lade herunter..."
        curl -L -o /tmp/tdb.7z "$LATEST_URL"
        
        echo "Entpacke TDB..."
        7z e /tmp/tdb.7z -o/tmp/tdb_extracted -y
        
        echo "Importiere TDB World Data..."
        mysql -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" world < "$(find /tmp/tdb_extracted -name '*.sql' | head -n 1)"
        
        # Cleanup
        rm -rf /tmp/tdb.7z /tmp/tdb_extracted
        echo "TDB Import abgeschlossen."
    else
        echo "FEHLER: Konnte keine TDB URL finden! URL war leer oder null."
        echo "Bitte prüfen: Gibt es im neuesten Release eine Datei, die NICHT '335' im Namen hat?"
    fi

else
    echo "Datenbank existiert bereits. Überspringe Setup."
fi

# --- 4. REALM IP ---
if [ ! -z "$TRINITY_REALM_IP" ] && [ "$1" = "auth" ]; then
    echo "Setze Realmlist IP: $TRINITY_REALM_IP"
    mysql -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" auth -e "UPDATE realmlist SET address = '$TRINITY_REALM_IP', name = 'Trinity Master Docker' WHERE id = 1;"
fi

# --- 5. START SERVER ---
if [ "$1" = "auth" ]; then
    exec "$BIN_DIR/authserver"
elif [ "$1" = "world" ]; then
    exec "$BIN_DIR/worldserver"
else
    exec "$@"
fi
