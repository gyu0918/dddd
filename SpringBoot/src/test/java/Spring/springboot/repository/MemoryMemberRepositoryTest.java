package Spring.springboot.repository;

import Spring.springboot.domain.Member;
import org.junit.jupiter.api.Test;

public class MemoryMemberRepositoryTest {
    MemoryMemberRepository repository = new MemoryMemberRepository();

    @Test
    public void save(){
        Member member = new Member();
        member.setName("spring");
        repository.save(member);
        repository.findById(member.getId());
    }
}
