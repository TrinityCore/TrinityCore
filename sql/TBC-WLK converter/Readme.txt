Convert DB from 2.4.3 to 3.0.x:

1. BACKUP your old db!
2. Run TBC-WLK_characters.sql in "characters" database.
3. Run TBC-WLK_world_run_only_once.sql in "world" database.
4. Run TBC-WLK_world.sql in "world" database.

After that you need to manually apply all sqls starting from 805_world_scripts.sql (in sql/updates)