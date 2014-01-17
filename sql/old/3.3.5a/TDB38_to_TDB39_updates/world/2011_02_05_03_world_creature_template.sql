-- Saving to instance for difficulty entries
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|1 WHERE `entry` IN (
34566,35615,35616, -- Anub arak
35347,35348,35349, -- Eydis Darkbane
35350,35351,35352, -- Fjola Lightbane
35216,35268,35269, -- Lord Jaraxxus
35447,35448,35449); -- Icehowl
