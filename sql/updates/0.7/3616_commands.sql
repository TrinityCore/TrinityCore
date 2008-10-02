-- Enhanced .addgo / .gameobject command
-- Now the user can also specify <LootID> and <SpawnTimeSecs>
DELETE FROM `command` WHERE `name` = 'addgo';
DELETE FROM `command` WHERE `name` = 'gameobject';
insert into `command` values ('gameobject',3,'Syntax: .gameobject #id <lootID> <spawntimeSecs>\r\n\r\nAdd a game object from game object templates to the world at your current location using the #id.\r\nlootID specifies the loot-template to be used and spawntimeSecs sets the spawntime, both are optional.');
insert into `command` values ('addgo',3,'Syntax: .addgo #id <lootID> <spawntimeSecs>\r\n\r\nAdd a game object from game object templates to the world at your current location using the #id.\r\nlootID specifies the loot-template to be used and spawntimesecs sets the spawntime, both are optional.\r\n\r\nNote: this is a copy of .gameobject.');
