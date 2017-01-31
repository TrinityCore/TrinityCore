-- Fix wrong npc flags
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry` IN (353, 1574, 1575);

UPDATE `creature_template` SET `npcflag`=8192 WHERE `entry`=35315; -- Narimar
UPDATE `creature_template` SET `npcflag`=8192 WHERE `entry`=35562; -- Korrah's Hippogryph
UPDATE `creature_template` SET `npcflag`=8192 WHERE `entry`=40769; -- Zazzix Boomride
UPDATE `creature_template` SET `npcflag`=8192 WHERE `entry`=40866; -- Swift Seahorse
UPDATE `creature_template` SET `npcflag`=8192 WHERE `entry`=41860; -- Elizil Wintermoth
UPDATE `creature_template` SET `npcflag`=8192 WHERE `entry`=43287; -- Swift Seahorse
UPDATE `creature_template` SET `npcflag`=8192 WHERE `entry`=43289; -- Swift Seahorse
UPDATE `creature_template` SET `npcflag`=8192 WHERE `entry`=43290; -- Francis Greene
UPDATE `creature_template` SET `npcflag`=8192 WHERE `entry`=43295; -- Salty McTavish
UPDATE `creature_template` SET `npcflag`=8192 WHERE `entry`=43398; -- Gorthul
UPDATE `creature_template` SET `npcflag`=8192 WHERE `entry`=43481; -- Dinorae Swiftfeather
UPDATE `creature_template` SET `npcflag`=8192 WHERE `entry`=54392; -- Ranela Featherglen
UPDATE `creature_template` SET `npcflag`=8193 WHERE `entry`=43389; -- Gorthul
UPDATE `creature_template` SET `npcflag`=8193 WHERE `entry`=43576; -- Gorthul
UPDATE `creature_template` SET `npcflag`=8193 WHERE `entry`=45904; -- Angus Stillmountain
UPDATE `creature_template` SET `npcflag`=8193 WHERE `entry`=45947; -- Jon-Jon Jellyneck
UPDATE `creature_template` SET `npcflag`=8194 WHERE `entry`=50367; -- Friz Groundspin
UPDATE `creature_template` SET `npcflag`=8194 WHERE `entry`=52646; -- Colin Swifthammer
UPDATE `creature_template` SET `npcflag`=8194 WHERE `entry`=52753; -- James Stillair
UPDATE `creature_template` SET `npcflag`=8194 WHERE `entry`=53008; -- Thysta
