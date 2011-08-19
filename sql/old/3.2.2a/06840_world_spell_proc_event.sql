-- Seal of Command
-- Change max procs per minute (ppm) to be read from the dbc
UPDATE spell_proc_event
SET ppmRate = 0
WHERE entry = 20375;
