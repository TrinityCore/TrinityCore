删除重复id,站在同一个地方的生物
最容易理解的方法:

--原来一共770884条数据

select min(guid) from creature group by id,position_x, position_y, position_z;--找出id,位置重复的生物数据中guid最小的,即最后要保存的数据.
--656429条结果

select * from creature where guid not in(select min(guid)from creature group by id,position_x, position_y, position_z);--删除要保存之外的数据.
--114455结果


select * from creature where guid not in(select min_guid from(select min(guid) as min_guid from creature group by id,position_x, position_y, position_z)as x);

--最终删除的114455条
delete from creature where guid not in(select min_guid from(select min(guid) as min_guid from creature group by id,position_x, position_y, position_z)as x);
--注意先备份,此处套as是防止mysql报1903错误

来源:https://blog.csdn.net/weixin_39820226/article/details/113553561,其中的方法二
