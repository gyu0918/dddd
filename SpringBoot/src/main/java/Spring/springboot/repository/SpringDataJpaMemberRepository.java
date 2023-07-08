package Spring.springboot.repository;

import Spring.springboot.domain.Member;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.Optional;

public interface SpringDataJpaMemberRepository extends JpaRepository<Member, Long>, MemberRepository {
    //interface끼리 implements할경우 extents쓴다.


    @Override
    Optional<Member> findByName(String name);
}
