using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        string filePath = "data.csv";

        List<DataRecord> records = ReadCsv(filePath);

        var filteredRecords = records.Where(r => r.Age > 30).ToList();

        foreach (var record in filteredRecords)
        {
            Console.WriteLine($"{record.Name}, {record.Age}, {record.Email}");
        }
    }

    static List<DataRecord> ReadCsv(string filePath)
    {
        var records = new List<DataRecord>();

        using (var reader = new StreamReader(filePath))
        {
            while (!reader.EndOfStream)
            {
                var line = reader.ReadLine();
                var values = line.Split(',');

                var record = new DataRecord
                {
                    Name = values[0],
                    Age = int.Parse(values[1]),
                    Email = values[2]
                };

                records.Add(record);
            }
        }

        return records;
    }
}

public class DataRecord
{
    public string Name { get; set; }
    public int Age { get; set; }
    public string Email { get; set; }
}
