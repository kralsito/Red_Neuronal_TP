function fetchData() {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve("Data fetched successfully!");
        }, 2000);
    });
}

async function fetchDataAsync() {
    try {
        let data = await fetchData();
        console.log(data);  // Output after 2 seconds: Data fetched successfully!
    } catch (error) {
        console.error("Error fetching data:", error);
    }
}

fetchDataAsync();
