-- Picnic Basket
UPDATE `gameobject_template` SET `flags`=0, `AIName`='' WHERE `entry`=187267;
DELETE FROM `smart_scripts` WHERE `entryorguid`=187267 AND `source_type`=1;
