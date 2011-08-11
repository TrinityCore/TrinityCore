-- Boss - Lord Marrowgar
UPDATE `creature_template` SET `mechanic_immune_mask`=667893759 WHERE `entry`=36612;
UPDATE `creature_template` SET `mechanic_immune_mask`=667893759 WHERE `entry`=37957;
UPDATE `creature_template` SET `mechanic_immune_mask`=667893759 WHERE `entry`=37958;
UPDATE `creature_template` SET `mechanic_immune_mask`=667893759 WHERE `entry`=37959;

-- Boss - Lady Deathwhisper
UPDATE `creature_template` SET `mechanic_immune_mask`=667893759 WHERE `entry`=36855;
UPDATE `creature_template` SET `mechanic_immune_mask`=667893759 WHERE `entry`=38106;
UPDATE `creature_template` SET `mechanic_immune_mask`=667893759 WHERE `entry`=38296;
UPDATE `creature_template` SET `mechanic_immune_mask`=667893759 WHERE `entry`=38297;

-- Boss - Deathbringer Saurfang
UPDATE `creature_template` SET `mechanic_immune_mask`=650854399 WHERE `entry`=38583;
UPDATE `creature_template` SET `mechanic_immune_mask`=650854399 WHERE `entry`=37813;
UPDATE `creature_template` SET `mechanic_immune_mask`=650854399 WHERE `entry`=38402;
UPDATE `creature_template` SET `mechanic_immune_mask`=650854399 WHERE `entry`=38582;

-- Boss - Prince Valanar 
UPDATE `creature_template` SET `mechanic_immune_mask`=650854399 WHERE `entry`=37970;
UPDATE `creature_template` SET `mechanic_immune_mask`=650854399 WHERE `entry`=38401;
UPDATE `creature_template` SET `mechanic_immune_mask`=650854399 WHERE `entry`=38784;
UPDATE `creature_template` SET `mechanic_immune_mask`=650854399 WHERE `entry`=38785;

-- Boss - Prince Keleseth
UPDATE `creature_template` SET `mechanic_immune_mask`=650854399 WHERE `entry`=37972;
UPDATE `creature_template` SET `mechanic_immune_mask`=650854399 WHERE `entry`=38399;
UPDATE `creature_template` SET `mechanic_immune_mask`=650854399 WHERE `entry`=38769;
UPDATE `creature_template` SET `mechanic_immune_mask`=650854399 WHERE `entry`=38770;

-- Boss - Prince Taldaram
UPDATE `creature_template` SET `mechanic_immune_mask`=650854399 WHERE `entry`=37973;
UPDATE `creature_template` SET `mechanic_immune_mask`=650854399 WHERE `entry`=38400;
UPDATE `creature_template` SET `mechanic_immune_mask`=650854399 WHERE `entry`=38771;
UPDATE `creature_template` SET `mechanic_immune_mask`=650854399 WHERE `entry`=38772;

-- Boss - Blood-Queen Lana'thel
UPDATE `creature_template` SET `mechanic_immune_mask`=801849343 WHERE `entry`=37955;
UPDATE `creature_template` SET `mechanic_immune_mask`=801849343 WHERE `entry`=38434;
UPDATE `creature_template` SET `mechanic_immune_mask`=801849343 WHERE `entry`=38435;
UPDATE `creature_template` SET `mechanic_immune_mask`=801849343 WHERE `entry`=38436;

-- Boss - Sindragosa
UPDATE `creature_template` SET `mechanic_immune_mask`=667893759 WHERE `entry`=36853;
UPDATE `creature_template` SET `mechanic_immune_mask`=667893759 WHERE `entry`=38265;
UPDATE `creature_template` SET `mechanic_immune_mask`=667893759 WHERE `entry`=38266;
UPDATE `creature_template` SET `mechanic_immune_mask`=667893759 WHERE `entry`=38267;

-- Volatile Ooze and Gas Cloud
UPDATE creature_template SET `mechanic_immune_mask`=650854399 WHERE entry IN (37697, 38758, 38759, 38604, 37562, 38760, 38761, 38602);
-- Little and Big Ooze
UPDATE creature_template SET `mechanic_immune_mask`=650853375 WHERE entry IN (36899, 38123, 36897, 38138);
-- Little Ooze taunt
UPDATE creature_template SET `flags_extra`=256 WHERE entry IN (36897, 38138);
