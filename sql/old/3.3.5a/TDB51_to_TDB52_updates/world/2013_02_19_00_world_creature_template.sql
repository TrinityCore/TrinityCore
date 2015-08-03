-- Issue 8590: Damage Boss ICC
-- Lord Marrowgar
UPDATE `creature_template` SET `dmg_multiplier`=55 WHERE `entry`=36612;
UPDATE `creature_template` SET `dmg_multiplier`=85 WHERE `entry`=37957;
UPDATE `creature_template` SET `dmg_multiplier`=75 WHERE `entry`=37958;
UPDATE `creature_template` SET `dmg_multiplier`=110 WHERE `entry`=37959;
-- Lady Deathwhisper
UPDATE `creature_template` SET `dmg_multiplier`=70 WHERE `entry`=36855;
UPDATE `creature_template` SET `dmg_multiplier`=100 WHERE `entry`=38106;
UPDATE `creature_template` SET `dmg_multiplier`=90 WHERE `entry`=38296;
UPDATE `creature_template` SET `dmg_multiplier`=140 WHERE `entry`=38297;
-- Deathbringer Saurfang
UPDATE `creature_template` SET `dmg_multiplier`=60 WHERE `entry`=37813;
UPDATE `creature_template` SET `dmg_multiplier`=90 WHERE `entry`=38402;
UPDATE `creature_template` SET `dmg_multiplier`=85 WHERE `entry`=38582;
UPDATE `creature_template` SET `dmg_multiplier`=120 WHERE `entry`=38583;
-- Festergut
UPDATE `creature_template` SET `dmg_multiplier`=75 WHERE `entry`=36626;
UPDATE `creature_template` SET `dmg_multiplier`=115 WHERE `entry`=37504;
UPDATE `creature_template` SET `dmg_multiplier`=100 WHERE `entry`=37505;
UPDATE `creature_template` SET `dmg_multiplier`=150 WHERE `entry`=37506;
-- Rotface
UPDATE `creature_template` SET `dmg_multiplier`=70 WHERE `entry`=36627;
UPDATE `creature_template` SET `dmg_multiplier`=100 WHERE `entry`=38390;
UPDATE `creature_template` SET `dmg_multiplier`=90 WHERE `entry`=38549;
UPDATE `creature_template` SET `dmg_multiplier`=140 WHERE `entry`=38550;
-- Professor Putricide
UPDATE `creature_template` SET `dmg_multiplier`=60 WHERE `entry`=36678;
UPDATE `creature_template` SET `dmg_multiplier`=90 WHERE `entry`=38431;
UPDATE `creature_template` SET `dmg_multiplier`=80 WHERE `entry`=38585;
UPDATE `creature_template` SET `dmg_multiplier`=120 WHERE `entry`=38586;
-- Blood Prince Council except Keleseth who is a caster
UPDATE `creature_template` SET `dmg_multiplier`=65 WHERE `entry` IN (37970,37973);
UPDATE `creature_template` SET `dmg_multiplier`=95 WHERE `entry` IN (38401,38400);
UPDATE `creature_template` SET `dmg_multiplier`=85 WHERE `entry` IN (38784,38771);
UPDATE `creature_template` SET `dmg_multiplier`=130 WHERE `entry` IN (38785,38772);
-- Blood Queen Lana'thel
UPDATE `creature_template` SET `dmg_multiplier`=60 WHERE `entry`=37955;
UPDATE `creature_template` SET `dmg_multiplier`=90 WHERE `entry`=38434;
UPDATE `creature_template` SET `dmg_multiplier`=80 WHERE `entry`=38435;
UPDATE `creature_template` SET `dmg_multiplier`=120 WHERE `entry`=38436;
-- Sindragosa (and damage for Sindragosa 10 who hits only 1)
UPDATE `creature_template` SET `dmg_multiplier`=60, mindmg=509, maxdmg=683, attackpower=805 WHERE `entry`=36853;
UPDATE `creature_template` SET `dmg_multiplier`=90 WHERE `entry`=38265;
UPDATE `creature_template` SET `dmg_multiplier`=80 WHERE `entry`=38266;
UPDATE `creature_template` SET `dmg_multiplier`=120 WHERE `entry`=38267;
