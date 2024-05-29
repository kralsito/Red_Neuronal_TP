public class InventoryItem
{
    public int Id { get; set; }
    public string Name { get; set; }
    public int Quantity { get; set; }
    public decimal Price { get; set; }
}
using Microsoft.EntityFrameworkCore;

public class InventoryContext : DbContext
{
    public DbSet<InventoryItem> InventoryItems { get; set; }

    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
    {
        optionsBuilder.UseSqlite("Data Source=inventory.db");
    }
}
using System;
using System.Linq;

public class InventoryManager
{
    public void AddItem(string name, int quantity, decimal price)
    {
        using (var context = new InventoryContext())
        {
            var item = new InventoryItem { Name = name, Quantity = quantity, Price = price };
            context.InventoryItems.Add(item);
            context.SaveChanges();
        }
    }

    public void RemoveItem(int id)
    {
        using (var context = new InventoryContext())
        {
            var item = context.InventoryItems.Find(id);
            if (item != null)
            {
                context.InventoryItems.Remove(item);
                context.SaveChanges();
            }
        }
    }

    public void ListItems()
    {
        using (var context = new InventoryContext())
        {
            var items = context.InventoryItems.ToList();
            foreach (var item in items)
            {
                Console.WriteLine($"{item.Id}: {item.Name}, {item.Quantity} units, ${item.Price}");
            }
        }
    }
}
