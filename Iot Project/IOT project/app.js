// ===============================
// SAMPLE SENSOR DATA
// ===============================

const temperatureData = [
    30, 29, 28, 28, 27, 26, 28, 30, 32, 30,
    29, 28, 29, 30, 32, 33, 32
];


const humidityData = [
    52, 54, 56, 57, 59, 61, 63, 61, 58,
    71, 67, 59, 52, 48, 55, 62, 64
];


const airQualityData = [
    980, 950, 1020, 1100, 1080, 1060,
    1000, 1120, 1300, 1250, 1050,
    1100, 1150, 1200, 1130, 1180, 1100
];


const timeLabels = [
    "12:00",
    "13:00",
    "14:00",
    "15:00",
    "16:00",
    "17:00",
    "18:00",
    "19:00",
    "20:00",
    "21:00",
    "22:00",
    "23:00",
    "00:00",
    "01:00",
    "02:00",
    "03:00",
    "04:00"
];


// ===============================
// TEMPERATURE GRAPH
// ===============================

new Chart(

    document.getElementById("temperatureChart"),

    {
        type: "line",

        data: {

            labels: timeLabels,

            datasets: [

                {
                    label: "Temperature",

                    data: temperatureData,

                    borderColor: "#e52b20",

                    backgroundColor: "transparent",

                    tension: 0.3,

                    pointRadius: 3,

                    borderWidth: 2
                }

            ]
        },

        options: {

            responsive: true,

            maintainAspectRatio: false,

            plugins: {

                legend: {
                    display: false
                }

            },

            scales: {

                y: {

                    min: 20,

                    max: 40
                },

                x: {

                    ticks: {

                        maxTicksLimit: 7
                    }
                }

            }
        }
    }

);


// ===============================
// HUMIDITY GRAPH
// ===============================

new Chart(

    document.getElementById("humidityChart"),

    {

        type: "line",

        data: {

            labels: timeLabels,

            datasets: [

                {

                    label: "Humidity",

                    data: humidityData,

                    borderColor: "#249447",

                    backgroundColor: "transparent",

                    tension: 0.3,

                    pointRadius: 3,

                    borderWidth: 2

                }

            ]

        },

        options: {

            responsive: true,

            maintainAspectRatio: false,

            plugins: {

                legend: {

                    display: false

                }

            },

            scales: {

                y: {

                    min: 30,

                    max: 80

                },

                x: {

                    ticks: {

                        maxTicksLimit: 7

                    }

                }

            }

        }

    }

);


// ===============================
// AIR QUALITY GRAPH
// ===============================

new Chart(

    document.getElementById("airQualityChart"),

    {

        type: "line",

        data: {

            labels: timeLabels,

            datasets: [

                {

                    label: "Air Quality",

                    data: airQualityData,

                    borderColor: "#086bc5",

                    backgroundColor: "transparent",

                    tension: 0.3,

                    pointRadius: 3,

                    borderWidth: 2

                }

            ]

        },

        options: {

            responsive: true,

            maintainAspectRatio: false,

            plugins: {

                legend: {

                    display: false

                }

            },

            scales: {

                y: {

                    min: 400,

                    max: 1400

                },

                x: {

                    ticks: {

                        maxTicksLimit: 7

                    }

                }

            }

        }

    }

);


// ===============================
// AIR QUALITY STATUS
// ===============================

function updateStatus(value) {

    const statusElement =
        document.getElementById("status");


    statusElement.classList.remove(
        "good",
        "moderate",
        "poor"
    );


    if (value < 1000) {

        statusElement.innerText = "GOOD";

        statusElement.classList.add("good");

    }

    else if (value < 2000) {

        statusElement.innerText = "MODERATE";

        statusElement.classList.add("moderate");

    }

    else {

        statusElement.innerText = "POOR";

        statusElement.classList.add("poor");

    }

}


// Initial status

updateStatus(812);


// ===============================
// CURRENT TIME
// ===============================

function updateTime() {

    const now = new Date();

    const time =
        now.toLocaleTimeString();

    document.getElementById(
        "lastUpdated"
    ).innerText = time;
}


updateTime();