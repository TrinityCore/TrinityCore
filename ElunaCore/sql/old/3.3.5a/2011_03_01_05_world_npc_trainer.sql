-- Set new tailoring requirement to learn crafting of Flying Carpet (based on 3.3.0 patch)
UPDATE `npc_trainer` SET `spellcost`=105000,`reqskillvalue`=300 WHERE `spell`=60969;
