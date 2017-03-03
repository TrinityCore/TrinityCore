-- Fix aggro bug with Diseased Young / Timber Wolf. Hack fix - Original Value 0
UPDATE creature_template SET flags_extra=2 WHERE entry=299; -- Diseased Young Wolf
UPDATE creature_template SET flags_extra=2 WHERE entry=69; -- Diseased Timber Wolf