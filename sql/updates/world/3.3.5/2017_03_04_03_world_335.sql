-- Revert Diseased Wolf Hack Fix
UPDATE creature_template SET flags_extra=0 WHERE entry=299; -- Diseased Young Wolf
UPDATE creature_template SET flags_extra=0 WHERE entry=69; -- Diseased Timber Wolf