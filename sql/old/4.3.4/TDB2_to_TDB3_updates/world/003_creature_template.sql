-- Creature: 37574 ([DND] Shaker - Small)
-- Add Flags 128+2: creature is trigger-NPC (invisible to players only) + creature does not aggro (ignore faction/reputation hostility)
UPDATE `creature_template` SET `flags_extra`=130 WHERE `entry`=37574;
-- Creature: 47569 - Hammon the Jaded
-- Update to Gossip + Trainer + Profession Trainer
UPDATE `creature_template` SET `npcflag`=81 WHERE `entry`=47569;

-- Creatue: 49842 - Forest Moth
-- Set InhabitType=4, Flying
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=49842;

-- Creatue: 40552 - Leora
-- Update to Gossip + Flight Master
UPDATE `creature_template` SET `npcflag`=8193 WHERE `entry`=40552;

-- Creature: 37543 - [DND] Shaker
-- Add Flags 128+2: creature is trigger-NPC (invisible to players only) + creature does not aggro (ignore faction/reputation hostility)
UPDATE `creature_template` SET `flags_extra`=130 WHERE `entry`=37543;

-- Creatue: 48735 - Gwen Armstead
-- Flags Innkeeper + Vendor + Vendor Food + Gossip
UPDATE `creature_template` SET `npcflag`=66177 WHERE `entry`=48735;

-- Set Vendor Flag 128
UPDATE `creature_template` SET `npcflag`=128 WHERE `entry` IN
(5191, -- Shalumon
51504); -- Velia Moonbow

-- Update to Gossip + Trainer + Profession Trainer
UPDATE `creature_template` SET `npcflag`=81 WHERE `entry` IN
(4159, -- Me'lynn
4160, -- Ainethil
4204, -- Firodren Mooncaller
4211, -- Dannelor
4212, -- Telonis
4213, -- Taladan
4753, -- Jartsam
30715, -- Feyden Darkin
52640, -- Rolf Karner
52642, -- Foreman Pernic
52645); -- Aessa Silverdew

-- Creatue: 4210 - Alegorn
-- Update to Gossip + Quest Giver + Trainer + Profession Trainer
UPDATE `creature_template` SET `npcflag`=83 WHERE `entry`=4210;
