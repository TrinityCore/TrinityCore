UPDATE gameobject_template set scriptName="go_altar_of_the_keepers" where entry = 130511;
UPDATE gameobject_template set scriptName="go_altar_of_archaedas" where entry = 133234;

UPDATE instance_template SET script="instance_uldaman" where map = 70;

-- Archaedas
UPDATE creature_template SET ScriptName="boss_archaedas" where entry = 2748;

-- Archaedas' minions
UPDATE creature_template SET ScriptName="mob_archaedas_minions" where entry in ('7309', '7077', '7076', '10120');

-- Stone keepers
UPDATE creature_template SET ScriptName="mob_stonekeepers" where entry = 4857;

