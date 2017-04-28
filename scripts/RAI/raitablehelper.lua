local RaiTableHelper = {}

function RaiTableHelper.new()

  --[[
    Random()
    @table The table to pick a random element from
    @return Element value e.g 131
  --]]
  function RaiTableHelper:Random(table)
    local rIndex = math.random(1, #table)
    return table[rIndex]
  end 

  --[[
    Merge()
    @table1 First table to merge with second table
    @table2 Second table to merge with first table
    @return The merged table
  --]]
  function RaiTableHelper:Merge(table1, table2)
    for k,v in pairs(table2) do 
      table1[k] = v 
    end

    return table1
  end

  return RaiTableHelper
end

return RaiTableHelper