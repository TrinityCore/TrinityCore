DELETE FROM `creature_addon` WHERE  `guid` IN (60167,78738,214421,356181);
DELETE FROM `gameobject_addon` WHERE  `guid` IN (24686,24685,24684,24683,32141,32142,32143);
UPDATE `quest_objectives` SET `ObjectID`='35753', `Amount`='1' WHERE  `ID`=264587;
UPDATE `quest_objectives` SET `ObjectID`='42463', `Amount`='1' WHERE  `ID`=265726;
UPDATE `creature_template` SET `npcflag`='3' WHERE  `entry` IN (20677,20679,63238);
DELETE FROM `game_event_creature` WHERE  `guid`=78738;
DELETE FROM `creature_formations` WHERE  `leaderGUID`=56878;
UPDATE `quest_template_addon` SET `SpecialFlags`='34' WHERE  `ID`=10935;
UPDATE `smart_scripts` SET `link`='0' WHERE  `source_type`=0 AND `id`=0 AND `link`=1 AND `entryorguid` IN (17404,19291,19292,20677,20678,20679);

