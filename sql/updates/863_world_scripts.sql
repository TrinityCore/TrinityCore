DELETE FROM `script_texts` WHERE `entry` BETWEEN -1060005 AND -1060000;
INSERT INTO script_texts
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`)
VALUES
   (-1060000, 'Emergency power activated! Initializing ambulatory motor! CLUCK!', NULL, NULL, 'Notfallenergie aktiviert! Ambulatorenantrieb wird gestartet! GLUCK!', NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL),
   (-1060001, 'Physical threat detected! Evasive action! CLUCK!', NULL, NULL, 'Körperliche Bedrohung entdeckt! Ausweichmanöver! GLUCK!', NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL),
   (-1060002, 'Threat analyzed! Activating combat plan beta! CLUCK!', NULL, NULL, 'Bedrohung analysiert! Gefechtsplan Beta wird aktiviert! GLUCK!', NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL),
   (-1060003, 'CLUCK! Sensors detect spatial anomaly -- danger imminent! CLUCK', NULL, NULL, 'GLUCK! Sensoren haben räumliche Anomalie entdeckt - Gefahr im Verzug! GLUCK!', NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL),
   (-1060004, 'No one challenges the wastevander nomads -- not even robotic chickens! ATTACK!', NULL, NULL, 'Niemand fordert die Wüsenläufernomaden heraus - auch keine Robothühner! ANGRIFF!', NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL),
   (-1060005, 'Cloaking systems online! CLUCK! Engaging cloak for transport to Booty Bay!', NULL, NULL, 'Tarnsysteme online! GLUCK! Tarnung für Transport nach Beutebucht wird aktiviert.', NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL);

UPDATE `creature_template` SET `ScriptName` = 'npc_OOX17' WHERE `entry` = 7784;
