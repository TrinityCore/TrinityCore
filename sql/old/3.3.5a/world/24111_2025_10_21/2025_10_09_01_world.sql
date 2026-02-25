-- Switch 'Just Summoned' to 'On just created' for Anzu summoning event
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=23057;
UPDATE `smart_scripts` SET `event_type`=63, `comment`="Invis Raven God Target - On Just Created - Run Script" WHERE `entryorguid`=23057 AND `source_type`=0 AND `id`=0;
