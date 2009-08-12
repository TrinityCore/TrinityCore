DELETE FROM `script_texts` WHERE `entry` between -1602042 AND -1602032;
DELETE FROM `script_texts` WHERE `entry` between -1602017 AND -1602011;
INSERT INTO `script_texts` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
(-1602011,'You wish to confront the master? You must weather the storm!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,14453,1,0,0,'ionar SAY_AGGRO'),
(-1602012,'Shocking ... I know!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,14456,1,0,0,'ionar SAY_SLAY_1'),
(-1602013,'You atempt the unpossible.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,14457,1,0,0,'ionar SAY_SLAY_2'),
(-1602014,'Your spark of light is ... extinguish.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,14458,1,0,0,'ionar SAY_SLAY_3'),
(-1602015,'Master... you have guests.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,14459,1,0,0,'ionar SAY_DEATH'),
(-1602016,'The slightest spark shall be your undoing.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,14454,1,0,0,'ionar SAY_SPLIT_1'),
(-1602017,'No one is safe!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,14455,1,0,0,'ionar SAY_SPLIT_2'),
(-1602032,'It is you who have destroyed my children? You... shall... pay!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13960,1,0,0,'volkhan SAY_AGGRO'),
(-1602033,'The armies of iron will conquer all!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13965, 1,0,0,'volkhan SAY_SLAY_1'),
(-1602034,'Ha, pathetic!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13966,1,0,0,'volkhan SAY_SLAY_2'),
(-1602035,'You have cost me too much work!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13967,1,0,0,'volkhan SAY_SLAY_3'),
(-1602036,'The master was right... to be concerned.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13968,1,0,0,'volkhan SAY_DEATH'),
(-1602037,'I will crush you beneath my boots!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13963,1,0,0,'volkhan SAY_STOMP_1'),
(-1602038,'All my work... undone!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13964,1,0,0,'volkhan SAY_STOMP_2'),
(-1602039,'Life from the lifelessness... death for you.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13961,1,0,0,'volkhan SAY_FORGE_1'),
(-1602040,'Nothing is wasted in the process. You will see....', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13962,1,0,0,'volkhan SAY_FORGE_2'),
(-1602041,'runs to his anvil!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,0,3,0,0,'volkhan EMOTE_TO_ANVIL'),
(-1602042,'prepares to shatter his Brittle Golems!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,0,3,0,0,'volkhan EMOTE_SHATTER');

UPDATE creature_template SET ScriptName='boss_volkhan' WHERE entry=28587;
UPDATE creature_template SET ScriptName='mob_molten_golem' WHERE entry=28695;
UPDATE creature_template SET ScriptName='npc_volkhan_anvil' WHERE entry=28823;
UPDATE creature_template SET ScriptName='boss_ionar' WHERE entry=28546;
UPDATE creature_template SET ScriptName='mob_spark_of_ionar' WHERE entry=28926;

