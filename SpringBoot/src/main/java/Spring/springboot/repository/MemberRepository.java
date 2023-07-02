package Spring.springboot.repository;

import Spring.springboot.domain.Member;

import java.util.List;
import java.util.Optional;

public interface MemberRepository {
    Member save(Member member);
    Optional<Member> findById(Long id);
    //static Optional<Member> findByName(String name);
    List<Member> findAll();
}
