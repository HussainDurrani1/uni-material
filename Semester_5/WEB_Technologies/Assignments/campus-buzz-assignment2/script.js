// CampusBuzz - Assignment 2
// Event data, Detail Page loading, and My Schedule (using localStorage)

const events = {
    "ai-seminar": {
        name: "AI & Future Seminar",
        society: "GDGoC UCP",
        category: "Seminar",
        date: "9 November 2026",
        time: "11:00 AM",
        venue: "Seminar Hall, UCP",
        price: 0,
        priceText: "Free Entry",
        img: "images/ai-seminar.svg",
        description: "A seminar on Artificial Intelligence and the future of jobs, where speakers will talk about AI tools, careers in AI, and how students can start learning AI step by step.",
        agenda: "Introduction to AI, AI tools demo, Career talk, Question and answer session"
    },
    "tech-fest": {
        name: "Tech Fest 2026",
        society: "IEEE UCP",
        category: "Technology",
        date: "12 November 2026",
        time: "10:00 AM",
        venue: "Main Auditorium, UCP",
        price: 0,
        priceText: "Free Entry",
        img: "images/tech-fest.svg",
        description: "The biggest technology event of the semester at UCP. Students will show their projects, attend tech talks, and take part in competitions like speed programming and project exhibition.",
        agenda: "Opening ceremony, Project exhibition, Speed programming, Tech talks, Prize distribution"
    },
    "book-fair": {
        name: "Book Fair 2026",
        society: "Library Society",
        category: "Academic",
        date: "15 - 17 November 2026",
        time: "9:00 AM",
        venue: "Central Library, UCP",
        price: 0,
        priceText: "Free Entry",
        img: "images/book-fair.svg",
        description: "A three-day book fair in the Central Library with stalls of books on literature, science, technology, and exam preparation at student-friendly prices.",
        agenda: "Book stalls, Author meet-up, Reading session, Discount sale"
    },
    "photo-exhibition": {
        name: "Photography Exhibition",
        society: "Media Society",
        category: "Arts & Media",
        date: "16 November 2026",
        time: "12:00 PM",
        venue: "Art Gallery, UCP",
        price: 0,
        priceText: "Free Entry",
        img: "images/photo-exhibition.svg",
        description: "An exhibition of the best photographs taken by UCP students, showing campus life, nature, and street photography.",
        agenda: "Exhibition opening, Photo walk, Best photo award"
    },
    "taakra": {
        name: "TAAKRA Cultural Night",
        society: "TAAKRA Society",
        category: "Cultural",
        date: "18 November 2026",
        time: "6:00 PM",
        venue: "UCP Main Ground",
        price: 500,
        priceText: "Rs. 500",
        img: "images/taakra.svg",
        description: "The famous cultural night of UCP with music, drama, dance performances, and food stalls. Students from different universities also take part in the competitions.",
        agenda: "Drama competition, Singing, Dance performances, Food street, Closing ceremony"
    },
    "cricket": {
        name: "Inter-University Cricket Tournament",
        society: "Sports Society",
        category: "Sports",
        date: "20 November 2026",
        time: "9:00 AM",
        venue: "UCP Cricket Ground",
        price: 0,
        priceText: "Free Entry",
        img: "images/cricket.svg",
        description: "A cricket tournament between university teams. Come and support the UCP team in the opening match.",
        agenda: "Opening match, Semi finals, Final match, Trophy ceremony"
    },
    "food-street": {
        name: "Food Street Festival",
        society: "Food Society",
        category: "Food & Festivals",
        date: "22 November 2026",
        time: "4:00 PM",
        venue: "Cafeteria Lawn, UCP",
        price: 200,
        priceText: "Rs. 200 Entry",
        img: "images/food-street.svg",
        description: "A food festival with stalls of desi, fast food, and desserts made by student societies and local vendors.",
        agenda: "Food stalls open, Eating competition, Live music, Closing"
    },
    "career-fair": {
        name: "Career Fair 2026",
        society: "Career Services Office",
        category: "Career",
        date: "25 November 2026",
        time: "9:00 AM",
        venue: "Main Hall, UCP",
        price: 0,
        priceText: "Free Entry",
        img: "images/career-fair.svg",
        description: "Companies visit UCP to meet students for jobs and internships. Bring your CV and meet employers from software houses and other industries.",
        agenda: "Company stalls, CV drop, On-spot interviews, Career counselling session"
    },
    "robotics": {
        name: "Robotics Competition",
        society: "Robotics Club",
        category: "Technology",
        date: "28 November 2026",
        time: "10:00 AM",
        venue: "Engineering Lab, UCP",
        price: 300,
        priceText: "Rs. 300",
        img: "images/robotics.svg",
        description: "Teams compete with their line-follower and obstacle-avoiding robots. The fastest and most accurate robot wins.",
        agenda: "Team registration, Round 1 races, Final round, Prize distribution"
    },
    "music-night": {
        name: "Music Night",
        society: "Music Society",
        category: "Cultural",
        date: "30 November 2026",
        time: "7:00 PM",
        venue: "Amphitheatre, UCP",
        price: 400,
        priceText: "Rs. 400",
        img: "images/music-night.svg",
        description: "An evening of live music with performances by the UCP Music Society, solo singers, and student bands.",
        agenda: "Solo performances, Band performances, Open mic, Closing jam session"
    }
};

// ---------- My Schedule functions (localStorage) ----------
// CampusBuzz is an event platform, not a shop: students do not buy events.
// The Assignment 2 selection feature is therefore named for events:
// students add events they want to attend to their own schedule.

function getSchedule() {
    const schedule = localStorage.getItem("campusBuzzSchedule");
    if (schedule) {
        return JSON.parse(schedule);
    }
    return [];
}

function saveSchedule(schedule) {
    localStorage.setItem("campusBuzzSchedule", JSON.stringify(schedule));
    showScheduleCount();
}

function addToSchedule(eventId) {
    const schedule = getSchedule();

    if (schedule.indexOf(eventId) !== -1) {
        alert(events[eventId].name + " is already in your schedule.");
        return;
    }

    schedule.push(eventId);
    saveSchedule(schedule);
    alert(events[eventId].name + " added to your schedule.");
}

function showScheduleCount() {
    const badge = document.getElementById("schedule-count");
    if (!badge) {
        return;
    }
    badge.textContent = getSchedule().length;
}

// ---------- Detail page ----------

function loadDetailPage() {
    const title = document.getElementById("detail-title");
    if (!title) {
        return;
    }

    const params = new URLSearchParams(window.location.search);
    let eventId = params.get("event");
    if (!eventId || !events[eventId]) {
        eventId = "tech-fest";
    }

    const event = events[eventId];
    document.getElementById("detail-img").src = event.img;
    document.getElementById("detail-img").alt = event.name;
    document.getElementById("detail-category").textContent = event.category;
    title.textContent = event.name;
    document.getElementById("detail-society").textContent = event.society;
    document.getElementById("detail-date").textContent = event.date + ", " + event.time;
    document.getElementById("detail-venue").textContent = event.venue;
    document.getElementById("detail-price").textContent = event.priceText;
    document.getElementById("detail-description").textContent = event.description;
    document.getElementById("detail-agenda").textContent = event.agenda;
    document.getElementById("detail-add-btn").onclick = function () {
        addToSchedule(eventId);
    };
}

// ---------- My Schedule page ----------

function showSchedulePage() {
    const tbody = document.getElementById("schedule-items");
    if (!tbody) {
        return;
    }

    const schedule = getSchedule();
    tbody.innerHTML = "";

    if (schedule.length === 0) {
        document.getElementById("schedule-empty").style.display = "block";
        document.getElementById("schedule-table").style.display = "none";
        document.getElementById("schedule-total-events").textContent = "0";
        return;
    }

    for (let i = 0; i < schedule.length; i++) {
        const event = events[schedule[i]];

        const row = document.createElement("tr");
        row.innerHTML =
            "<td>" + event.name + "</td>" +
            "<td>" + event.date + ", " + event.time + "</td>" +
            "<td>" + event.venue + "</td>" +
            "<td>" + event.priceText + "</td>" +
            "<td><button class='remove-btn' onclick='removeFromSchedule(\"" + schedule[i] + "\")'>Remove</button></td>";
        tbody.appendChild(row);
    }

    document.getElementById("schedule-total-events").textContent = schedule.length;
}

function removeFromSchedule(eventId) {
    let schedule = getSchedule();
    schedule = schedule.filter(function (item) {
        return item !== eventId;
    });
    saveSchedule(schedule);
    showSchedulePage();
}

function clearSchedule() {
    const schedule = getSchedule();
    if (schedule.length === 0) {
        alert("Your schedule is already empty.");
        return;
    }
    localStorage.removeItem("campusBuzzSchedule");
    showScheduleCount();
    showSchedulePage();
    alert("Your schedule has been cleared.");
}

// Run on every page
showScheduleCount();
loadDetailPage();
showSchedulePage();
