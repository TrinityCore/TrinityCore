create index idx_ahbot_history_item on ahbot_history(item);
create index idx_ahbot_history_won on ahbot_history(won);
create index idx_ahbot_history_auction_house on ahbot_history(auction_house);
create index idx_ahbot_history_category on ahbot_history(category);
create index idx_ahbot_history_buytime on ahbot_history(buytime);

create index idx_ahbot_price_item on ahbot_price(item);
create index idx_ahbot_price_auction_house on ahbot_price(auction_house);

create index idx_ai_playerbot_guild_tasks_value on ai_playerbot_guild_tasks(value);
create index idx_ai_playerbot_guild_tasks_guildid on ai_playerbot_guild_tasks(guildid);
create index idx_ai_playerbot_guild_tasks_type on ai_playerbot_guild_tasks(type);
create index idx_ai_playerbot_guild_tasks_owner on ai_playerbot_guild_tasks(owner);

