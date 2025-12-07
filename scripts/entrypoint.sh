#!/bin/bash
set -e

BIN_DIR="/opt/trinitycore/bin"
ETC_DIR="/opt/trinitycore/etc"

echo "Starte TrinityCore Container..."

if [ ! -f "$ETC_DIR/authserver.conf" ]; then
    echo "Authserver Config nicht gefunden. Kopiere default..."
    cp "$ETC_DIR/authserver.conf.dist" "$ETC_DIR/authserver.conf"
fi

if [ ! -f "$ETC_DIR/worldserver.conf" ]; then
    echo "Worldserver Config nicht gefunden. Kopiere default..."
    cp "$ETC_DIR/worldserver.conf.dist" "$ETC_DIR/worldserver.conf"
    sed -i 's|^DataDir = .*|DataDir = "/opt/trinitycore/data"|g' "$ETC_DIR/worldserver.conf"
fi

echo "Warte auf Datenbank Verbindung..."
while ! nc -z db 3306; do   
  sleep 1
done
echo "Datenbank ist erreichbar!"

if [ "$1" = "auth" ]; then
    echo "Starte authserver..."
    exec "$BIN_DIR/authserver"
elif [ "$1" = "world" ]; then
    echo "Starte worldserver..."
    exec "$BIN_DIR/worldserver"
else
    exec "$@"
fi
