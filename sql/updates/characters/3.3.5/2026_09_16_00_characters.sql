-- AI WorldFactionId (data/elwynn/factions/README.md) - social/political
-- affiliation for an AI agent, separate from Faction.dbc/FactionTemplate.dbc
-- (which govern TrinityCore combat reaction/reputation). Appended at the
-- end of ai_agents' own column list, not next to agent_type/map_id/
-- spawn_id, the same "append, don't reindex" convention the 2026_08_30_01
-- migration's own control_mode column already established - keeps every
-- existing fields[N] index in AgentPersistence::LoadAgents() unchanged.
-- Defaults to 0 (WorldFactions::Unaffiliated / NEUTRAL_UNAFFILIATED) - a
-- pre-existing row, or one AIWorld's WorldFactionCatalog never classifies,
-- stays Unaffiliated until AIWorldMgr::RunSpawnReconciliation()'s own
-- WorldFactionCatalog refresh pass resolves it from
-- world.ai_world_faction_entry_defaults.
ALTER TABLE `ai_agents`
ADD COLUMN `world_faction_id` INT UNSIGNED NOT NULL DEFAULT 0 AFTER `control_mode`;
