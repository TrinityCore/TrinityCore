-- Transition some creatures to use new CREATURE_FLAGS_EXTRA_NO_PLAYER_DAMAGE_REQ
-- 27685/27686/27531: Target creatures for Quest 12416 ("Heated Battle")
-- 24051/24063: Target creatures for Quest 11243 ("If Valgarde Falls...")
-- 28034/28035/28036: Targets for Quest 12508 ("Mopping Up")
UPDATE `creature_template` SET `flags_extra`=(`flags_extra`|2097152) WHERE `entry` IN (27685,27686,27531,24051,24063,28034,28035,28036);
