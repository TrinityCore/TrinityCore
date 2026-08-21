#!/bin/bash
# Substitutes __TC_DB_USER__/__TC_DB_PASSWORD__ placeholders in a mounted
# conf template with the real values from the environment, then execs the
# server binary against the rendered copy. Keeps deploy/*.conf as plain,
# reviewable templates while the actual credentials only ever come from
# .env / compose environment.
set -euo pipefail

: "${TC_DB_USER:?TC_DB_USER must be set}"
: "${TC_DB_PASSWORD:?TC_DB_PASSWORD must be set}"

conf_src="$1"
binary="$2"
conf_dst="/tmp/$(basename "$conf_src")"

sed \
  -e "s/__TC_DB_USER__/${TC_DB_USER}/g" \
  -e "s/__TC_DB_PASSWORD__/${TC_DB_PASSWORD}/g" \
  "$conf_src" > "$conf_dst"

exec "$binary" -c "$conf_dst"
