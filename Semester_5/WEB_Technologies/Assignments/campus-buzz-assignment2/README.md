# CampusBuzz - Assignment 2

Students: Muhammad Hussain Durrani & Ali Hamza
Group: Null & Void
Course: Web Technologies, UCP

## Design
The design is the same as the final Assignment 1 version (v2, built from the
design image): dark navy navbar with yellow active pill, gradient hero with the
tilted UCP building photo, pastel category pills, event cards with the category
pill and title on the image, and coloured entry pills.

## What Assignment 2 adds
1. Bootstrap 5 (CDN) on all 6 pages - grid for the event cards and the detail
   page, badge for the schedule count in the navbar, striped table on the
   My Schedule page, form-control / form-select on the contact form, and an
   alert box for the empty schedule.
2. Animations - fadeIn (page load), slideUp (hero, cards, boxes) and zoomIn
   (hero and detail images), plus hover lift and image zoom on cards.
3. Event Detail Page - event-detail.html, opened from the View Details button
   on every event card, filled by script.js from the ?event= link.
4. Add to Schedule + My Schedule page (my-schedule.html).

## Why it is called "My Schedule" and not a cart
The Assignment 2 document asks for an "Add to Cart" feature with a new page.
CampusBuzz is an event platform, not a shop - students do not buy events.
So the same feature is named for events:

- "Add to Cart" button      ->  "Add to Schedule" button
- Cart page                  ->  "My Schedule" page (my-schedule.html)
- Quantity / total / checkout -> removed; an event is either in your
  schedule or it is not. The schedule page lists the event, its date and
  time, venue and entry, with a Remove button and a total events count.

The feature works the same way: selected items are saved (localStorage),
shown on their own page, can be removed, and the navbar badge shows how
many events are in the schedule.

## Pages
- index.html - Home
- events.html - Events list (all 10 events)
- event-detail.html - Detail page for one event
- my-schedule.html - My Schedule
- about.html - About Us
- contact.html - Contact
