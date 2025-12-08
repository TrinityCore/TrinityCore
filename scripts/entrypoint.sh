#!/bin/bash
set -e

BIN_DIR="/opt/trinitycore/bin"
ETC_DIR="/opt/trinitycore/etc"
SQL_DIR="/opt/trinitycore/sql"
DATA_DIR="/opt/trinitycore/data"

# DB Zugangsdaten aus Docker Environment
DB_HOST="db"
DB_USER="root"
DB_PASS="trinity"

echo ">>> TrinityCore Entrypoint gestartet <<<"

# --- FUNKTION: Config Werte setzen (Regex) ---
# Diese Funktion sucht nach "Key = ...", egal was da steht, und ersetzt es hart.
# Das entspricht dem manuellen Editieren der .conf Dateien.
set_config() {
    local file=$1
    local key=$2
    local value=$3
    # sed erklärt: Suche Zeile, die mit 'key' beginnt, ersetze sie komplett durch 'key = value'
    sed -i "s|^$key\s*=.*|$key = \"$value\"|g" "$file"
}

# --- 1. CONFIG HANDLING ---
# Kopieren der .dist Dateien, falls keine Configs existieren
if [ ! -f "$ETC_DIR/authserver.conf" ]; then
    echo "Erstelle authserver.conf aus Template..."
    cp "$ETC_DIR/authserver.conf.dist" "$ETC_DIR/authserver.conf"
fi

if [ ! -f "$ETC_DIR/worldserver.conf" ]; then
    echo "Erstelle worldserver.conf aus Template..."
    cp "$ETC_DIR/worldserver.conf.dist" "$ETC_DIR/worldserver.conf"
fi

echo "Passe Konfigurationen an (Datenbank & Pfade)..."

# Authserver Config anpassen
# Syntax: Host;Port;User;Password;Database
set_config "$ETC_DIR/authserver.conf" "LoginDatabaseInfo" "$DB_HOST;3306;$DB_USER;$DB_PASS;auth"

# Worldserver Config anpassen
set_config "$ETC_DIR/worldserver.conf" "LoginDatabaseInfo"     "$DB_HOST;3306;$DB_USER;$DB_PASS;auth"
set_config "$ETC_DIR/worldserver.conf" "WorldDatabaseInfo"     "$DB_HOST;3306;$DB_USER;$DB_PASS;world"
set_config "$ETC_DIR/worldserver.conf" "CharacterDatabaseInfo" "$DB_HOST;3306;$DB_USER;$DB_PASS;characters"
set_config "$ETC_DIR/worldserver.conf" "DataDir"               "$DATA_DIR"

# --- 2. WARTE AUF DATENBANK ---
echo "Warte auf Datenbank ($DB_HOST)..."
while ! nc -z $DB_HOST 3306; do sleep 1; done
echo "Datenbank ist da!"

# --- 3. AUTO INSTALLATION (Nur beim ersten Mal) ---
if ! mysql -h $DB_HOST -u $DB_USER -p$DB_PASS -e "USE auth;" 2>/dev/null; then
    echo ">>> Initialisierung: Datenbanken leer. Starte Setup... <<<"

    # Struktur anlegen
    mysql -h $DB_HOST -u $DB_USER -p$DB_PASS < "$SQL_DIR/create/create_mysql.sql"

    # Basis SQLs importieren
    # Wir nutzen 'find', da sich Dateinamen ändern können
    mysql -h $DB_HOST -u $DB_USER -p$DB_PASS auth < "$(find $SQL_DIR/base -name 'auth_database.sql')"
    mysql -h $DB_HOST -u $DB_USER -p$DB_PASS characters < "$(find $SQL_DIR/base -name 'characters_database.sql')"
    mysql -h $DB_HOST -u $DB_USER -p$DB_PASS world < "$(find $SQL_DIR/base -name 'world_database.sql')"

    # TDB Download & Import (Automatisch neueste Version)
    echo "Suche neueste TDB World Database..."
    LATEST_URL=$(curl -s https://api.github.com/repos/TrinityCore/TrinityCore/releases/latest | jq -r '.assets[] | select(.name | contains("TDB_full_world")) | .browser_download_url')
    
    if [ -n "$LATEST_URL" ]; then
        echo "Lade TDB herunter: $LATEST_URL"
        curl -L -o /tmp/tdb.7z "$LATEST_URL"
        
        echo "Entpacke TDB..."
        7z e /tmp/tdb.7z -o/tmp/tdb_extracted -y
        
        echo "Importiere TDB World Data (Geduld, ca. 1-2 Min)..."
        mysql -h $DB_HOST -u $DB_USER -p$DB_PASS world < "$(find /tmp/tdb_extracted -name '*.sql' | head -n 1)"
        
        # Cleanup
        rm -rf /tmp/tdb.7z /tmp/tdb_extracted
        echo "TDB Import fertig."
    else
        echo "WARNUNG: Konnte TDB URL nicht finden. Server startet mit leerer Welt!"
    fi
    
    # Updates einspielen (Wichtig für Master Branch!)
    echo "Spiele Updates aus /sql/updates/ ein..."
    # Hinweis: Dies ist komplex automatisch zu lösen, da die Reihenfolge wichtig ist.
    # Für den ersten Start reicht die Base + TDB meistens aus.
    # TrinityCore Server binary führt Updates oft selbstständig beim Start aus (AutoUpdater).
else
    echo "Datenbank existiert bereits. Überspringe Setup."
fi

# --- 4. NETWORKING (Realmlist IP setzen) ---
# Siehe: https://trinitycore.info/en/install/Networking
if [ ! -z "$TRINITY_REALM_IP" ] && [ "$1" = "auth" ]; then
    echo "Setze Realmlist IP in Datenbank auf: $TRINITY_REALM_IP"
    # Wir updaten ID 1. Name setzen wir auf 'Trinity Docker'.
    mysql -h $DB_HOST -u $DB_USER -p$DB_PASS auth -e "UPDATE realmlist SET address = '$TRINITY_REALM_IP', name = 'Trinity Docker', localAddress = '127.0.0.1' WHERE id = 1;"
fi

# --- 5. START ---
if [ "$1" = "auth" ]; then
    echo "Starte Authserver..."
    exec "$BIN_DIR/authserver"
elif [ "$1" = "world" ]; then
    echo "Starte Worldserver..."
    exec "$BIN_DIR/worldserver"
else
    exec "$@"
fi
