-- Limit Flame Tsunami buff to Lava Blazes only
DELETE FROM spell_script_target WHERE entry = 60430;
INSERT INTO spell_script_target (entry, type, targetEntry) VALUES
  (60430, 1, 30643),
  (60430, 1, 31317);
