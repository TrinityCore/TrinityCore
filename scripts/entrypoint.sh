#!/bin/bash
set -e

BIN_DIR="/opt/trinitycore/bin"
ETC_DIR="/opt/trinitycore/etc"
BACKUP_DIR="/opt/trinitycore/etc-backup" # New backup path
SQL_DIR="/opt/trinitycore/sql"
DATA_DIR="/opt/trinitycore/data"

# DB Zugangsdaten
DB_HOST="db"
DB_USER="root"
DB_PASS="trinity"

echo ">>> TrinityCore MASTER Entrypoint gestartet <<<"

# --- 0. RESTORE CONFIGS ---
# Checks if the dist files are missing (due to volume mount) and restores them from backup
if [ ! -f "$ETC_DIR/authserver.conf.dist" ]; then
    echo "Volume ist leer. Stelle Standard-Configs aus Backup wieder her..."
    cp -r "$BACKUP_DIR/"* "$ETC_DIR/"
fi

# Config Helper
set_config() {
# ... (Rest des Skripts bleibt gleich)
