UPDATE `quest_template` SET `SpecialFlags`=2 WHERE `entry`=4770;
UPDATE `creature_template` SET `ScriptName`='npc_swiftmountain' WHERE `entry`=10427;
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000149 AND -1000147;
INSERT INTO `script_texts`
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `comment`)
VALUES
  (-1000147, 'Lets go $N. I am ready to start to Whitereach Post.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, NULL),
  (-1000148, 'This seems to me trusted. If we move to the east, we are  probably... Aah!  Wyvern attack !', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, NULL),
  (-1000149, 'Thanks so much... From here I find the way back to the Whitereach Post. Speak with Motega Firemane, maybe you can persuade him to send me home.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, NULL);
