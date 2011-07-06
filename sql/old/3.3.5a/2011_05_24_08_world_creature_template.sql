-- Fix some screwed up / hacked up factions
UPDATE `creature_template` SET `faction_H`=`faction_A` WHERE `subname` IN ('The Assurance','The Cloudkisser','The Bravery');
UPDATE `creature_template` SET `faction_H`=`faction_A` WHERE `entry` IN (25013,25014);
