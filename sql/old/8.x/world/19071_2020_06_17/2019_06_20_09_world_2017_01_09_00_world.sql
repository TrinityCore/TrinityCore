-- Valkyr Shadowguard Imunity
UPDATE `creature_template` SET `mechanic_immune_mask` = 
1|          -- charm
2|          -- disorient
4|          -- disarm
8|          -- distract
16|         -- fear
32|         -- grip
64|         -- root
256|        -- silence
512|        -- sleep
4096|       -- freeze
8192|       -- knockout
65536|      -- polymorph
131072|     -- banish
524288|     -- shackle
1048576|    -- mount
4194304|    -- turn
8388608|    -- horror
33554432|   -- interrupt
536870912   -- sapped
WHERE `entry` IN (36609,39120,39121,39122);
