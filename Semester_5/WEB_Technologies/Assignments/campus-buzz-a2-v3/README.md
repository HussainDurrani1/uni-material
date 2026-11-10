# CampusBuzz - Assignment 2 (V3 - new design)

Students: Muhammad Hussain Durrani & Ali Hamza
Group: Null & Void
Course: Web Technologies, UCP

## Design
This version follows the new redesign images (made with ChatGPT from our pages):
dark navy navbar with a Categories link and the My Schedule count badge, blue to
purple gradient heroes, a search bar and stat chips in the Home hero with a
floating "Upcoming Event" card on the UCP building photo, 8 category boxes with
a small line under each name, a "This Week at UCP" strip, event cards with the
title under the image, a "Why use CampusBuzz?" section, clubs and testimonial
panels, gradient call-to-action banners, and a footer with columns (Quick Links,
For Students, Get in Touch) above the assignment credit line.

The event data is unchanged from Assignment 1: the same 10 events, dates,
venues, societies and entry prices. Where a redesign image showed different
data (for example a "Sports Gala" card or TAAKRA at Rs. 200 in one image), the
real project data was kept (TAAKRA is Rs. 500, as on the Schedule image).

## What Assignment 2 adds
1. Bootstrap 5 (CDN) on all 6 pages - grid for cards and page columns, badge
   for the schedule count, striped table on My Schedule, form-control /
   form-select on the contact and filter forms, alert for the empty schedule.
2. Animations - fadeIn, slideUp, zoomIn, plus hover lift and image zoom.
3. Event Detail Page - event-detail.html, filled by script.js from ?event=.
4. Add to Schedule + My Schedule page (my-schedule.html) - confirmed with our
   teacher: JavaScript is allowed in Assignment 2, and "Add to Schedule /
   My Schedule" is accepted instead of "Add to Cart", because CampusBuzz is an
   event platform, not a shop - students attend events, they do not buy them.
   There is no quantity, total or checkout; adding the same event twice is
   blocked. The schedule is saved in localStorage.
5. Events page filters (script.js) - search box, category drop-down and
   Free / Paid price pills, with a live "events found" count.

## Teacher confirmations (Fri Nov 6, Web Technologies class)
- JavaScript is allowed in Assignment 2.
- "Add to Schedule / My Schedule" naming is acceptable instead of a cart.
- Submission is a ZIP file uploaded through the portal.

## Pages
- index.html - Home
- events.html - Events list (all 10 events) with filters
- event-detail.html - Detail page for one event
- my-schedule.html - My Schedule
- about.html - About Us
- contact.html - Contact
