DELETE FROM `quest_template` WHERE (`Id`=26918);
DELETE FROM `creature_queststarter` WHERE (`quest`=26918);
DELETE FROM `gameobject_queststarter` WHERE (`quest`=26918);
DELETE FROM `creature_questender` WHERE (`quest`=26918);
DELETE FROM `gameobject_questender` WHERE (`quest`=26918);
DELETE FROM `areatrigger_involvedrelation` WHERE (`quest`=26918);

DELETE FROM `quest_template` WHERE `Id` in (14283, 26948, 27067);
DELETE FROM `creature_queststarter` WHERE `quest` in (14283, 26948, 27067);
DELETE FROM `gameobject_queststarter` WHERE `quest` in (14283, 26948, 27067);
DELETE FROM `creature_questender` WHERE `quest` in (14283, 26948, 27067);
DELETE FROM `gameobject_questender` WHERE `quest` in (14283, 26948, 27067);
DELETE FROM `areatrigger_involvedrelation` WHERE `quest` in (14283, 26948, 27067);