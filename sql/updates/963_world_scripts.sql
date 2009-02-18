UPDATE creature_template set ScriptName='mob_illidari_spawn' WHERE entry IN (22075,22074,19797);
UPDATE `creature_template` SET `ScriptName`='mob_torloth_the_magnificent' WHERE `entry`='22076';
UPDATE creature_template SET ScriptName='npc_lord_illidan_stormrage' WHERE entry=22083;
delete from creature where id=22083;
INSERT INTO creature (id, map, spawnMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, DeathState, MovementType)
 VALUES (22083, 530, 1, 0, 0, -4635.75, 1386.32, 137.34, 5.72398, 25,0, 0, 9955, 6774, 0, 0);
update gameobject_template set scriptname='go_crystal_prison' where entry=185126;

DELETE FROM script_texts WHERE entry BETWEEN -1000374 and -1000366;
INSERT INTO script_texts (entry, content_default, type, comment) VALUES
(-1000366, 'So you have defeated the Crimson Sigil. You now seek to challenge my rule? Not even Arthas could defeat me, yet you dare to even harbor such thoughts? Then I say to you, come! Come $N! The Black Temple awaits...', 1, 'Quest: Battle of the crimson watch - END_TEXT'),

(-1000367, 'At your command, my liege...', 0, 'TorlothAnim - First'),
(-1000368, 'Destroy them, Torloth. Let lose their blood like a river upon this hallowed ground.', 0, 'Quest: Battle of the crimson watch TorlothAnim - Second'),
(-1000369, 'As you desire, Lord Illidan.', 0, 'Quest: Battle of the crimson watch TorlothAnim - Third'),
(-1000370, 'Yes, Lord Illidan, I would sacrifice to you this magnificent physique. On this day you will fall - another victim of Torloth...', 0, 'Quest: Battle of the crimson watch TorlothAnim - Fourth'),

(-1000371, 'What manner of fool dares stand before Illidan Stormrage? Soldiers, destroy these insects!', 1, 'Quest: Battle of the crimson watch WavesInfo - First'),
(-1000372, 'You are no challenge for the Crimson Sigil. Mind breakers, end this nonsense.', 1, 'Quest: Battle of the crimson watch WavesInfo - Second'),
(-1000373, 'Run while you still can. The highlords come soon...', 1, 'Quest: Battle of the crimson watch WavesInfo - Third'),
(-1000374, 'Torloth your master calls!', 1, 'Quest: Battle of the crimson watch WavesInfo - Fourth');

