-- Texts with wrong broadcast texts (typos, both texts are completely different)
-- Disobedient Dragonmaw Peon, these texts are related to another quest
DELETE FROM `creature_text` WHERE `CreatureID` = 23311 AND `GroupID` = 0 AND `ID` IN (6,7);
-- Moodle
UPDATE `creature_text` SET `BroadcastTextId` = 28395 WHERE `CreatureID` = 28122 AND `GroupID` = 3 AND `ID` = 0;
UPDATE `creature_text` SET `BroadcastTextId` = 28394 WHERE `CreatureID` = 28122 AND `GroupID` = 3 AND `ID` = 1;
-- Text https://www.wowhead.com/npc=28122/moodle#comments:id=914017:reply=436172 will be just replaced by text
-- from broadcast_text, since there's no such text and never was
-- And another https://www.wowhead.com/npc=28122/moodle#comments:id=914017:reply=436172
UPDATE `creature_text` SET `BroadcastTextId` = 28401 WHERE `CreatureID` = 28122 AND `GroupID` = 4 AND `ID` = 1;
UPDATE `creature_text` SET `BroadcastTextId` = 28402 WHERE `CreatureID` = 28122 AND `GroupID` = 4 AND `ID` = 2;
UPDATE `creature_text` SET `BroadcastTextId` = 28399 WHERE `CreatureID` = 28122 AND `GroupID` = 4 AND `ID` = 3;
UPDATE `creature_text` SET `BroadcastTextId` = 28397 WHERE `CreatureID` = 28122 AND `GroupID` = 4 AND `ID` = 4;
UPDATE `creature_text` SET `BroadcastTextId` = 28398 WHERE `CreatureID` = 28122 AND `GroupID` = 4 AND `ID` = 5;
-- Instructor Hroegar
UPDATE `creature_text` SET `BroadcastTextId` = 30576 WHERE `CreatureID` = 29915 AND `GroupID` = 0 AND `ID` = 7;

UPDATE `creature_text` a LEFT JOIN `broadcast_text` b ON a.`BroadcastTextId` = b.`ID` SET a.`Text` = b.`Text` WHERE b.`Text1` = '' AND a.`Text` != b.`Text`;
UPDATE `creature_text` a LEFT JOIN `broadcast_text` b ON a.`BroadcastTextId` = b.`ID` SET a.`Text` = b.`Text1` WHERE b.`Text` = '' AND a.`Text` != b.`Text1`;
