-- remove wrong trigger on SV Hunter spell Disengage
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=781;
