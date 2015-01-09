-- Fix faction for Draconic for Dummies objects
UPDATE `gameobject_template` SET `faction`=35 WHERE `entry` IN (180665,180667);
