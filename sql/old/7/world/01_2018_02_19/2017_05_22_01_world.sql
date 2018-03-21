--
DELETE FROM `creature_questender` WHERE `quest` NOT IN (SELECT `ID` FROM `quest_template`);
DELETE FROM `creature_queststarter` WHERE `quest` NOT IN (SELECT `ID` FROM `quest_template`);
DELETE FROM `gameobject_questender` WHERE `quest` NOT IN (SELECT `ID` FROM `quest_template`);
DELETE FROM `gameobject_queststarter` WHERE `quest` NOT IN (SELECT `ID` FROM `quest_template`);
