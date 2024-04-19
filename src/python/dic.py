file_counts={"jpg":10, "txt":14, "csv":2, "py":23}
print(file_counts["jpg"])

file_counts["txt"]=18
del file_counts["py"]
print(file_counts)

for extension in file_counts:
    print(extension)

for extension,amount in file_counts.items():
    print(f"There are {amount} files with the .{extension} format")

print(file_counts.keys())
print(file_counts.values())
