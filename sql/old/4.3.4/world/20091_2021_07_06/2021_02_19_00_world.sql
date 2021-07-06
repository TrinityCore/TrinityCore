DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_mage_fingers_of_frost_charges';
UPDATE `spell_proc` SET `AttributesMask`= `AttributesMask`|0x10 WHERE `SpellId`= 44544;
