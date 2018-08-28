SET @ENTRY := 40927;
UPDATE `creature_template` SET `AIName`="" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;

UPDATE `creature_template` SET `ScriptName`= 'npc_rajh_orb_of_the_sun' WHERE `ScriptName`= 'npc_orb_of_the_sun';
UPDATE `creature_template` SET `ScriptName`= 'npc_rajh_solar_winds' WHERE `ScriptName`= 'npc_solar_winds';

-- Loot
DELETE FROM `creature_loot_template` WHERE entry IN (39378, 48815);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `Reference`, `MaxCount`) VALUES
(39378, 393780, 100, 1, 393780, 2),
(48815, 488150, 100, 1, 488150, 2),
(48815, 52078, 100, 1, 0, 1); -- Chaos Orb


DELETE FROM `reference_loot_template` WHERE `Entry` IN (393780, 488150);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
-- Normal
(393780, 56108, 0, 1, 1, 1, 1),
(393780, 56101, 0, 1, 1, 1, 1),
(393780, 56107, 0, 1, 1, 1, 1),
(393780, 56099, 0, 1, 1, 1, 1),
(393780, 56098, 0, 1, 1, 1, 1),
(393780, 56104, 0, 1, 1, 1, 1),
(393780, 56105, 0, 1, 1, 1, 1),
(393780, 56106, 0, 1, 1, 1, 1),
(393780, 56102, 0, 1, 1, 1, 1),
(393780, 56100, 0, 1, 1, 1, 1),
-- Heroic
(488150, 56433, 0, 1, 1, 1, 1),
(488150, 56430, 0, 1, 1, 1, 1),
(488150, 56434, 0, 1, 1, 1, 1),
(488150, 56428, 0, 1, 1, 1, 1),
(488150, 56429, 0, 1, 1, 1, 1),
(488150, 56435, 0, 1, 1, 1, 1),
(488150, 56436, 0, 1, 1, 1, 1),
(488150, 56432, 0, 1, 1, 1, 1),
(488150, 56427, 0, 1, 1, 1, 1),
(488150, 56431, 0, 1, 1, 1, 1);
