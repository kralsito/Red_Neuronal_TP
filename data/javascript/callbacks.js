function getData(callback) {
    setTimeout(() => {
        let data = "Data retrieved";
        callback(data);
    }, 2000);
}

function processData(data) {
    console.log("Processing data:", data);
}

getData(processData);  // Output after 2 seconds: Processing data: Data retrieved
