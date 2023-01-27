-- Fix quest Recruiting Efforts (49400)

-- Table `gameobject_template`
UPDATE `gameobject_template` SET `Data1` = 49400, `Data10` = 0 WHERE (entry = 278308);

-- Editing the SmartAI script of [GameObject] ENTRY 278308 (name: Irontide Recruiting Poster)

-- Table gameobject_template
UPDATE `gameobject_template` SET `AIName` = '' WHERE `entry` = 278308;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (`source_type` = 1 AND `entryorguid` = 278308);