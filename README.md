```
NAME
        koreantrack - logs and tracks watches of videos

        if a string has spaces, please add "quotes"

DESCRIPTION

        koreantrack add
            used to add an entry

            -n, --name    (NEEDED)
                name of (for example, an episode that you just watched in korean)

            -l, --link    (optional)
                link of (for example, where you found that episode)
                doesn't have to be an actual link, could also be a path to a file on your pc...

            -w, --watches (optional, default sets to 1)
                ammount of times you have watched/rewatched a series


        koreantrack rm
            used to remove an entry

            -i, --id    (NEEDED)
                id of entry (for example, the episode)


        koreantrack show
            used to list all or specific entry

            -without flags-
                list all entries in watches sorted order

            -i, --id
                shows full entry with link


        koreantrack inc
            used to increment a specific entry's watches

            -i --id     (NEEDED)
                id of entry to be incremented

        
        koreantrack logs
            used to log all entries ever added, 
            it cats watched-list.txt in koreanTracker/
            you can modify the file however you want or add entries manually,
            this will not interfere with any of koreantracker

        
        koreantrack -h, --h
            will show this file
```