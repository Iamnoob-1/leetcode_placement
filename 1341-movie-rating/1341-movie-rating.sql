# Write your MySQL query statement below
(select name as results
from users u
left join movierating mr on mr.user_id=u.user_id
group by u.user_id 
order by count(*) desc,u.name asc
limit 1
)

union all
(
select m.title as results
from movies m
left join movierating mr on m.movie_id=mr.movie_id
where mr.created_at>='2020-02-01' and mr.created_at<'2020-03-01'
group by m.movie_id
order by avg(mr.rating) desc,m.title asc
limit 1
)
