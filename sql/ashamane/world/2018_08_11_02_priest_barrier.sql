
-- Fix Priest Barrier Spell
UPDATE areatrigger_scripts SET entry = 1489 WHERE ScriptName = "at_pri_power_word_barrier";
UPDATE areatrigger_template SET ScriptName = "at_pri_power_word_barrier" WHERE Id = 5802;
