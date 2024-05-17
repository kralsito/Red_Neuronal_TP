function createList() {
    let list = document.createElement("ul");
    for (let i = 1; i <= 5; i++) {
        let item = document.createElement("li");
        item.textContent = "Item " + i;
        list.appendChild(item);
    }
    document.body.appendChild(list);
}

createList();
